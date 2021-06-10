export function cargarDatos(clave){
    return JSON.parse(localStorage.getItem(clave)) || [];
}

export function guardarDatos(clave,datos){
    localStorage.setItem(clave,JSON.stringify(datos));
}

export function borrarDato(clave){
    if(confirm(`¿Desea borrar el elemento indicado: ${clave}?`))
        localStorage.removeItem(clave);
}

export function borrarDatos(){
    if(confirm("¿Desea borrar todos los elementos de la base de datos?"))
        localStorage.clear();
}