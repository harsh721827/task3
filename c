import React, { useState } from 'react';

function App() {
  // State to store input value
  const [input, setInput] = useState('');

  // State to store the list of names
  const [items, setItems] = useState([]);

  // State to track which item is being edited (null if none)
  const [editIndex, setEditIndex] = useState(null);

  // Function to handle add or update
  const handleAddOrUpdate = () => {
    if (input.trim() === '') return; // Don’t add empty input

    if (editIndex === null) {
      // 🟢 Add new item
      setItems([...items, input]); // Add input to list
    } else {
      // 🟡 Update existing item
      const updatedItems = [...items];
      updatedItems[editIndex] = input; // Replace the value
      setItems(updatedItems);
      setEditIndex(null); // Clear editing mode
    }

    // Clear the input box
    setInput('');
  };

  // Function to handle delete
  const handleDelete = (index) => {
    const newList = items.filter((_, i) => i !== index);
    setItems(newList);
    if (editIndex === index) {
      // If the item being edited is deleted
      setEditIndex(null);
      setInput('');
    }
  };

  // Function to handle edit
  const handleEdit = (index) => {
    setInput(items[index]); // Show the item in input box
    setEditIndex(index);    // Remember which index we're editing
  };

  return (
    <div style={{ padding: '20px' }}>
      <h2>Simple React CRUD App</h2>

      {/* Input box to type or edit name */}
      <input
        type="text"
        value={input}
        onChange={(e) => setInput(e.target.value)}
        placeholder="Enter name"
      />

      {/* Add or Update button depending on the mode */}
      <button onClick={handleAddOrUpdate}>
        {editIndex === null ? 'Add' : 'Update'}
      </button>

      <hr />

      {/* Display the list of items */}
      <ul>
        {items.map((item, index) => (
          <li key={index}>
            {item}{' '}
            {/* Edit button */}
            <button onClick={() => handleEdit(index)}>Edit</button>{' '}
            {/* Delete button */}
            <button onClick={() => handleDelete(index)}>Delete</button>
          </li>
        ))}
      </ul>
    </div>
  );
}

export default App;
