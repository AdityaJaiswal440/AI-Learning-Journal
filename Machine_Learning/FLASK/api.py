from flask import Flask,jsonify,request

app = Flask(__name__)

items = [
    {"id":1, "name":"Item 1", "desciption":"This's item-1"},
    {"id":2, "name":"Item 2", "desrciption":"This's item-2"}
]

@app.route('/')
def home():
    return "Welcome to the Home Page."

@app.route('/items/<int:item_id>',methods = ['GET'])
def get_items(item_id):
    item = next((item for item in items if item["id"] == item_id), None)
    
    # 2. If not found, CREATE IT on the fly
    if item is None:
        new_item = {
            "id": item_id,
            "name": f"Auto-Generated Item {item_id}",
            "description": "Created because it was not found."
        }
        items.append(new_item)
        return jsonify({"message": "Item created successfully", "item": new_item}), 201
    return jsonify(items)

@app.route('/items/<int:item_id>',methods = ['GET'])
def get_item(item_id):
    item = next((item for item in items if item["id"]==item_id),None)
    if item is None:
        return jsonify({"error":"item not found"})
    return jsonify(item)

@app.route('/items',methods = ['POST'])
def create_items():
    if not request.json or not 'name' in request.json:
        return jsonify({"error":"item not found"})
    new_item = {
        "id" : items[-1]["id"] + 1 if items else 1,
        "name" : request.json["name"],
        "desciption" : request.json["description"]
    }
    items.append(new_item)
    return jsonify(new_item)

@app.route('/items/<int:item_id>',methods = ['PUT'])
def update_item(item_id):
    item = next((item for item in items if items["id"] == item_id),None)
    if items is None:
        return jsonify({"error":"Item not Found"})
    item["name"] = request.json.get('name',item['name'])
    item["description"] = request.json.get('description',item['description'])
    return jsonify(item)

@app.route('/items/<int:item_id>',methods = ['DELETE'])
def delete_item(item_id):
    global items
    items = [items for item in items if item["id"] != item_id]
    return jsonify({"result":"Item deleted!!"})
    

if __name__ == '__main__':
    app.run(debug=True)