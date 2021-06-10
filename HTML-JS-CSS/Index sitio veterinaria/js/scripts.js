import {crearTabla, obtenerIdSeleccionado} from "./tabla.js";
import Anuncio_Mascota from "./anuncio.js";

let Id = 0;
let listaAnuncios = [];

const txtTitulo = document.getElementById('txtTitulo');
const txtDescripcion = document.getElementById('txtDescripcion');
const rdoPerro = document.getElementById('rdoPerro');
const rdoGato = document.getElementById('rdoGato');
const txtPrecio = document.getElementById('txtPrecio');
const txtRaza = document.getElementById('txtRaza');
const datNacimiento = document.getElementById('datNacimiento');
const sVacunacion = document.getElementById('sVacunacion');
const btnGuardar = document.getElementById('btnGuardar');
const divTablaDatos = document.getElementById('dTablaDatos');

window.addEventListener('load', inicializarManejadores());

function inicializarManejadores(){
    Id = cargarId();
    listaAnuncios = cargarDatos();
    if(listaAnuncios.length>0){
        divTablaDatos.appendChild(crearTabla(listaAnuncios));
    }
    crearSpinner();
}

btnGuardar.addEventListener('click', (e)=>{
    let auxAnimal;

    if(rdoPerro.checked){
        auxAnimal = 'Perro';
    }
    if(rdoGato.checked){
        auxAnimal = 'Gato';
    }

    let auxAnuncioMascota = new Anuncio_Mascota(Id, txtTitulo.value, "venta", txtDescripcion.value, txtPrecio.value, auxAnimal, txtRaza.value, datNacimiento.value, sVacunacion.value);
    listaAnuncios.push(auxAnuncioMascota);
    Id++;
    guardarDatos();
    mostrarDatos();
});

btnModificar.addEventListener('click', (e)=>{
    let auxAnimal;
    let IdSel = obtenerIdSeleccionado();

    if(rdoPerro.checked){
        auxAnimal = 'Perro';
    }
    if(rdoGato.checked){
        auxAnimal = 'Gato';
    }
    let auxAnuncioMascota = new Anuncio_Mascota(IdSel, txtTitulo.value, "venta", txtDescripcion.value, txtPrecio.value, auxAnimal, txtRaza.value, datNacimiento.value, sVacunacion.value);
    modificarAnuncio(auxAnuncioMascota);
});

btnBorrar.addEventListener('click', (e)=>{
    let IdSel = obtenerIdSeleccionado();

    borrarAnuncio(IdSel);
});

/*let animal0 = new Anuncio_Mascota(0, 'Titulo', '', 'Descripcion', 100, 'Perro', 'Bulldog', '19/02/1992', 'SI');
alert(animal0.mostrarDatosAnuncio());*/

function cargarDatos(){
    let auxLista = JSON.parse(localStorage.getItem('anunciosAnimales')) || [];
    return auxLista;
}

function cargarId(){
    return JSON.parse(localStorage.getItem('idAnunciosAnimales')) || 0;
}

function guardarDatos(){
    localStorage.setItem('anunciosAnimales', JSON.stringify(listaAnuncios));
    localStorage.setItem('idAnunciosAnimales', JSON.stringify(Id));
}

function borrarTodosDatos(){
    localStorage.clear();
}

//En base al formulario genera una nueva persona y la retorna
function obtenerAnuncio(id){
    let auxSexo;

    if(rdoM.checked){
        auxSexo='m';
    }
    else if(rdoF.checked){
        auxSexo='f';
    }
    else{
        auxSexo='x';
    }

    return (new Persona(id, txtNombre.value, txtApellido.value, txtEmail.value, auxSexo));
}

//Elimina todos los datos mostrados y carga nuevamente los disponibles(refresca)
function mostrarDatos(){
    while(divTablaDatos.hasChildNodes()){
        divTablaDatos.removeChild(divTablaDatos.firstChild);
    }

    divTablaDatos.appendChild(crearSpinner());

    setTimeout(()=>{
        divTablaDatos.removeChild(divTablaDatos.firstChild);
        if(listaAnuncios.length>0)
            divTablaDatos.appendChild(crearTabla(listaAnuncios));
        else
            divTablaDatos.innerHTML = "<p>Sin datos para mostrar.</p>";
    }, 3000);
}

function modificarAnuncio(anuncio){
    //Validar datos
    let indice = BuscarIndiceAnuncio(anuncio.id);

    if(indice>=0){
        listaAnuncios[indice].Titulo = anuncio.titulo;
        listaAnuncios[indice].Transaccion = anuncio.transaccion;
        listaAnuncios[indice].Descripcion = anuncio.descripcion;
        listaAnuncios[indice].Precio = anuncio.precio;
        listaAnuncios[indice].Animal = anuncio.animal;
        listaAnuncios[indice].Raza = anuncio.raza;
        listaAnuncios[indice].FechaNacimiento = anuncio.fechaNacimiento;
        listaAnuncios[indice].Vacunacion = anuncio.vacunacion;

        guardarDatos();
        mostrarDatos();
    }
    else{
        alert("Id inexistente.");
    }
}

function borrarAnuncio(id){
    let indice = BuscarIndiceAnuncio(id);

    if(indice>=0){
        listaAnuncios.splice(indice, 1);
        guardarDatos();
        mostrarDatos();
    }
    else{
        alert("Id inexistente.");
    }
}

//Busca indice en array de una persona por su id
function BuscarIndiceAnuncio(id){
    //Validar datos
    for(let i=0; i<listaAnuncios.length; i++){
        if(listaAnuncios[i].id == id)
            return i;
    }
    
    return -1;
}

function crearSpinner(){
    const spinner = document.createElement('img');
    spinner.setAttribute('src', './img/spinner-perro.gif');
    return spinner;
}

function crearSpinner2(contenedor,archivo,espera=1000){
    const spinner = document.createElement('img');
    spinner.setAttribute("src", archivo);
    spinner.setAttribute("alt", "spinner");
    vaciarContenedor(contenedor);
    contenedor.appendChild(spinner);
    setTimeout(() => {
        vaciarContenedor(contenedor);
    }, espera);
}
