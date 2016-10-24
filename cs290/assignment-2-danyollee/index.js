/*
 * Add your JS in this file.
 */

//For removing the sticky notes
var dismissButton = document.getElementsByClassName('dismiss-button');
for(var i = 0; i < dismissButton.length; i++){
  dismissButton[i].addEventListener("click", removeSticky);
}

function removeSticky(event){
  event.currentTarget.parentNode.remove();
  console.log("==clicked on the dismiss button");
}


//For opening the modal
var addButton = document.getElementById('add-note-button');
addButton.addEventListener("click", openModal);

var modalPopUp = document.getElementById('add-note-modal');
var modalBackdrop = document.getElementById('modal-backdrop');

function openModal(event){
  console.log("==clicked on the add button");
  modalPopUp.classList.remove('hidden');
  modalBackdrop.classList.remove('hidden');
}

var dismissModalButton = document.getElementsByClassName('modal-close-button');
for(var i = 0; i < dismissModalButton.length; i++){
  dismissModalButton[i].addEventListener("click", dismissModal);
}

function dismissModal(event){
  console.log("==modal was cancelled. New sticky was not created");
  modalPopUp.classList.add('hidden');
  modalBackdrop.classList.add('hidden');
}

var cancelModal = document.getElementsByClassName('modal-cancel-button');
for(var i = 0; i < cancelModal.length; i++){
  cancelModal[i].addEventListener("click", dismissModal);
}


//For adding a sticky note
var addToDo = document.getElementsByClassName('modal-accept-button');
for(var i = 0; i < addToDo.length; i++){
  addToDo[i].addEventListener("click", readInputs);
}

var whatInput;
var whereInput;
var whenInput;
var whoInput;
var detailsInput;
function readInputs(event){
  console.log("==You clicked to store the new sticky note structure into variables");
  //For getting the inputs from user. Will be stored when user click the "Add ToDo" button
  whatInput = document.getElementById("todo-input-what").value;
  whereInput = document.getElementById("todo-input-where").value;
  whenInput = document.getElementById("todo-input-when").value;
  whoInput = document.getElementById("todo-input-who").value;
  detailsInput = document.getElementById("todo-input-details").value;
  console.log("==inputs are " + whatInput + " " + whereInput + " " + whenInput + " " + whoInput + " " + detailsInput);
  modalPopUp.classList.add('hidden');
  modalBackdrop.classList.add('hidden');

  createSticky(whatInput, whereInput, whenInput, whoInput, detailsInput);
}

function createSticky(){
  var newHeader;
  var newBody;
  var newWhere;
  var newWhen;
  var newWho;
  var newDetails;
  var newSpan;
  var newDismiss;
  var bolded;
  var input;

  console.log("==whatInput is '" + whatInput + "'");

  if(whatInput == ""){
    dismissModal();
  }
  else{
    console.log("==creating a new sticky note");
    var section = document.createElement("section");
    section.classList.add("todo");

    var main = document.querySelector("main");
    main.appendChild(section);

    newHeader = document.createElement("h2");
    input = document.createTextNode(whatInput);
    newHeader.appendChild(input);
    section.appendChild(newHeader);
  }

  if(whereInput != ""){
    addWhere(newBody, bolded, newWhere, whereInput, section);
  }

  if(whenInput != ""){
    addWhen(newBody, bolded, newWhere, whenInput, section);
  }

  if(whoInput != ""){
    addWho(newBody, bolded, newWhere, whoInput, section);
  }

  if(detailsInput != ""){
    addDetails(newBody, bolded, newWhere, detailsInput, section);
  }

  //adding the dismiss button to each sticky
  var temp = document.createElement("div");
  temp.innerHTML = "&times;";
  temp.classList.add("dismiss-button");
  section.appendChild(temp);
  temp.addEventListener("click", removeSticky);

  clearInputs(whatInput, whereInput, whenInput, whoInput, detailsInput);

}

function clearInputs(){
  console.log("==got to clearInputs");
  document.getElementById("todo-input-what").value = " ";
  document.getElementById("todo-input-where").value = " ";
  document.getElementById("todo-input-when").value = " ";
  document.getElementById("todo-input-who").value = " ";
  document.getElementById("todo-input-details").value = " ";
}

function addWhere(newBody, bolded, newWhere, whereInput, section){
  newBody = document.createElement("p");
  newBody.classList.add("indent-wrapped");
  bolded = document.createElement("span");
  bolded.classList.add("where");
  bolded.innerHTML = "where: ";
  newBody.appendChild(bolded);
  newWhere = document.createTextNode(whereInput);
  newBody.appendChild(newWhere);
  section.appendChild(newBody);
}

function addWhen(newBody, bolded, newWhere, whenInput, section){
  newBody = document.createElement("p");
  newBody.classList.add("indent-wrapped");
  bolded = document.createElement("span");
  bolded.classList.add("when");
  bolded.innerHTML = "when: ";
  newBody.appendChild(bolded);
  newWhen = document.createTextNode(whenInput);
  newBody.appendChild(newWhen);
  section.appendChild(newBody);
}

function addWho(newBody, bolded, newWhere, whoInput, section){
  newBody = document.createElement("p");
  newBody.classList.add("indent-wrapped");
  bolded = document.createElement("span");
  bolded.classList.add("who");
  bolded.innerHTML = "who: ";
  newBody.appendChild(bolded);
  newWho = document.createTextNode(whoInput);
  newBody.appendChild(newWho);
  section.appendChild(newBody);
}

function addDetails(newBody, bolded, newWhere, detailsInput, section){
  newBody = document.createElement("p");
  newDetails = document.createTextNode(detailsInput);
  newBody.appendChild(newDetails);
  section.appendChild(newBody);
}
