import Persona from './personas.js';
import {cargarDatos,guardarDatos,borrarDato,borrarDatos} from './ls.js';
import crearTabla from './tablas.js';

const divTablaDatos=document.getElementById("divTablaDatos");

const btnAgregarPers=document.getElementById("btnAgregar");
const btnModificarPers=document.getElementById("btnModificar");
const btnEliminarPers=document.getElementById("btnEliminar");
const btnEliminarBD=document.getElementById("btnEliminarTodo");
const btnResetForm=document.getElementById("btnReset");

const inId=document.getElementById("idId");
const inNombre=document.getElementById("idNombre");
const inApellido=document.getElementById("idApellido");
const inEmail=document.getElementById("idEmail");
const inEdad=document.getElementById("idEdad");

const rdoSexoF=document.getElementById("rSexoF");
const rdoSexoM=document.getElementById("rSexoM");
const chkTatuajes=document.getElementById("cTatuajes");
const chkPiercings=document.getElementById("cPiercings");
const chkOtros=document.getElementById("cOtros");

const rutaSpinner="./assets/img/spinner-cargando.gif";
const esperaSpinner=1000;

let arrayPersonas=null;
let idArrayPersonas=null;
inicializarManejadores();
renderizarTabla(divTablaDatos,crearTabla(arrayPersonas,false));

window.addEventListener('load',e=>inicializarManejadores);

function inicializarManejadores(e){
    console.log("Inicializando manejadores...");
    arrayPersonas=cargarDatos("arrayPersonas");
    idArrayPersonas=cargarDatos("idArrayPersonas");
    if(idArrayPersonas.length==0)
        idArrayPersonas=-1;
}

function renderizarTabla(contenedor,tabla){
    if(contenedor!=null && tabla!=null){        
        vaciarContenedor(contenedor);
        divTablaDatos.appendChild(tabla);
    }
}

function vaciarContenedor(contenedor){
    if(contenedor!=null)
        while(contenedor.hasChildNodes())
            contenedor.removeChild(contenedor.firstChild);
}

btnAgregarPers.addEventListener('click',(e)=>{
    e.preventDefault();
    idArrayPersonas=idArrayPersonas+1;
    let auxPers=new Persona(parseInt(idArrayPersonas),
        inNombre.value,
        inApellido.value,
        inEmail.value,
        parseInt(inEdad.value),
        rdoSexoF.checked,
        chkTatuajes.checked,
        chkPiercings.checked,
        chkOtros.checked
    );

    crearSpinner(divTablaDatos,rutaSpinner);

    setTimeout(() => {        
        Persona.altaPersona(arrayPersonas,auxPers);
        renderizarTabla(divTablaDatos,crearTabla(arrayPersonas,false));
    }, esperaSpinner);
});

btnModificarPers.addEventListener('click',(e)=>{
    let auxPers=new Persona(parseInt(inId.value),
        inNombre.value,
        inApellido.value,
        inEmail.value,
        parseInt(inEdad.value),
        rdoSexoF.checked,
        chkTatuajes.checked,
        chkPiercings.checked,
        chkOtros.checked
    );

    crearSpinner(divTablaDatos,rutaSpinner);

    setTimeout(() => {        
        Persona.modificarPersona(arrayPersonas,auxPers);
        renderizarTabla(divTablaDatos,crearTabla(arrayPersonas,false));
    }, esperaSpinner);
});

btnEliminarPers.addEventListener('click',(e)=>{
    let auxPers=new Persona(inId.value,
        inNombre.value,
        inApellido.value,
        inEmail.value,
        parseInt(inEdad.value),
        rdoSexoF.checked,
        chkTatuajes.checked,
        chkPiercings.checked,
        chkOtros.checked
    );

    crearSpinner(divTablaDatos,rutaSpinner);

    setTimeout(() => {        
        Persona.bajaPersona(arrayPersonas,auxPers);
        if(arrayPersonas.length>0)
            renderizarTabla(divTablaDatos,crearTabla(arrayPersonas,false));
        else
            vaciarContenedor(divTablaDatos);
    }, esperaSpinner);
});

btnEliminarBD.addEventListener('click',(e)=>{
    crearSpinner(divTablaDatos,rutaSpinner);

    setTimeout(() => {     
        vaciarContenedor(divTablaDatos);
        borrarDatos();
        if(localStorage.length==0){
            arrayPersonas.splice(0);
            idArrayPersonas=-1;
        }
        renderizarTabla(divTablaDatos,crearTabla(arrayPersonas,false));
    }, esperaSpinner);

});

btnResetForm.addEventListener('click',(e)=>{});

window.addEventListener('click',(e)=>{
    const trMetaData=e.target.parentNode.dataset;
    let idTr=trMetaData.id;
    if(idTr>=0){        
        inId.value=idTr;
        inNombre.value=trMetaData.nombre;
        inApellido.value=trMetaData.apellido;
        inEmail.value=trMetaData.email;
        inEdad.value=trMetaData.edad;
        
        rdoSexoF.checked=(trMetaData.sexo=="Femenino");
        rdoSexoM.checked=(trMetaData.sexo=="Masculino"),
        chkTatuajes.checked=(trMetaData.tatuajes=="Sí"),
        chkPiercings.checked=(trMetaData.piercings=="Sí"),
        chkOtros.checked=(trMetaData.otros=="Sí")        
    }
});

function crearSpinner(contenedor,archivo){
    const spinner=document.createElement("img");
    spinner.setAttribute("src",archivo);
    spinner.setAttribute("alt","spinner");
    vaciarContenedor(contenedor);
    contenedor.appendChild(spinner);
}
