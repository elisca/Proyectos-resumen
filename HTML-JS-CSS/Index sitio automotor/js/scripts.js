import {crearTabla, obtenerIdSeleccionado} from "./tabla.js";
import Anuncio_Auto from "./anuncio.js";

let Id = 0;
let listaAnuncios = [];

const txtTitulo = document.getElementById('txtTitulo');
const lstTransaccion = document.getElementById('lstTransaccion');
const txtDescripcion = document.getElementById('txtDescripcion');
const numPrecio = document.getElementById('numPrecio');
const numPuertas = document.getElementById('numPuertas');
const numKMs = document.getElementById('numKMs');
const numPotencia = document.getElementById('numPotencia');

const btnGuardar = document.getElementById('btnGuardar');
const btnModificar = document.getElementById('btnModificar');
const btnBorrar = document.getElementById('btnBorrar');
const btnRestablecer = document.getElementById('btnRestablecer');

const divTablaDatos = document.getElementById('dTablaDatos');

const LAPSO_ESPERA=3000;

window.addEventListener('load', inicializarManejadores());

function inicializarManejadores(){
    alert("Boton \"Modificar\" con función a corregir.");
    Id = cargarId();
    listaAnuncios = cargarDatos();
    if(listaAnuncios.length>0){
        divTablaDatos.appendChild(crearTabla(listaAnuncios));
    }
    crearSpinner();
}

btnGuardar.addEventListener('click', (e)=>{
    e.preventDefault();
    let auxAnuncioAuto=new Anuncio_Auto(
        Id,
        txtTitulo.value,
        lstTransaccion.value,
        txtDescripcion.value,
        numPrecio.value,
        numPuertas.value,
        numKMs.value,
        numPotencia.value
    );
        
    listaAnuncios.push(auxAnuncioAuto);
    Id++;
    guardarDatos();
    mostrarDatos();
});

btnModificar.addEventListener('click', (e)=>{
    e.preventDefault();
    let IdSel = obtenerIdSeleccionado();

    let auxAnuncioAuto=new Anuncio_Auto(
        IdSel,
        txtTitulo.value,
        lstTransaccion.value,
        txtDescripcion.value,
        numPrecio.value,
        numPuertas.value,
        numKMs.value,
        numPotencia.value
    );
    modificarAnuncio(auxAnuncioAuto);
});

btnBorrar.addEventListener('click', (e)=>{
    let IdSel = obtenerIdSeleccionado();

    borrarAnuncio(IdSel);
});

function cargarDatos(){
    let auxLista = JSON.parse(localStorage.getItem('anunciosAutos')) || [];
    return auxLista;
}

function cargarId(){
    return JSON.parse(localStorage.getItem('idAnunciosAutos')) || 0;
}

function guardarDatos(){
    localStorage.setItem('anunciosAutos', JSON.stringify(listaAnuncios));
    localStorage.setItem('idAnunciosAutos', JSON.stringify(Id));
}

function borrarTodosDatos(){
    localStorage.clear();
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
    }, LAPSO_ESPERA);
}

function modificarAnuncio(anuncio){
    let indice = BuscarIndiceAnuncio(anuncio.id);

    if(indice>=0){
        listaAnuncios[indice].Titulo = anuncio.titulo;
        listaAnuncios[indice].Transaccion = anuncio.transaccion;
        listaAnuncios[indice].Descripcion = anuncio.descripcion;
        listaAnuncios[indice].Precio = anuncio.precio;
        listaAnuncios[indice].Puertas = anuncio.puertas;
        listaAnuncios[indice].Kilometraje = anuncio.kilometraje;
        listaAnuncios[indice].Potencia = anuncio.potencia;

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

//Busca indice en array por su id
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
    spinner.setAttribute('src', './img/llanta-spinner.gif');
    return spinner;
}