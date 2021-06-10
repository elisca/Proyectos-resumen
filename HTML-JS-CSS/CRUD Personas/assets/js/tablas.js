export default function crearTabla(array,incluirPie=false,...pie){
    if(array.length>0){
        const table=document.createElement("table");
        const encabezado=crearEncabezado(array[0]);
        const cuerpo=crearCuerpo(array);
    
        table.appendChild(encabezado);
        table.appendChild(cuerpo);
    
        if(incluirPie){
            const pieTabla=crearPie(pie);
            table.appendChild(pieTabla);
        }
    
        table.setAttribute("style","border: 1px solid black;");
        table.setAttribute("style","border-collapse: collapse;");
    
        return table;
    }
    console.warn("Array vacío, no puede generarse una tabla.");
    return null;
}

function crearEncabezado(item){
    const thead=document.createElement("thead");
    const tr=document.createElement("tr");

    Object.keys(item).forEach(e => {
        const th=document.createElement("th");
        const cont=document.createTextNode(e);

        th.appendChild(cont);
        th.setAttribute("style","border: 1px solid black;")

        tr.appendChild(th);
    });

    thead.appendChild(tr);

    return thead;
}

function crearCuerpo(array){
    const tbody=document.createElement("tbody");
    
    array.forEach(e=>{
        const tr=document.createElement("tr");
        
        for (const key in e){
            const td=document.createElement("td");
            const cont=document.createTextNode(e[key]);

            td.appendChild(cont);
            td.setAttribute("style","border: 1px solid black;")

            tr.appendChild(td);
            
            tr.setAttribute(`data-${key}`,e[key]);
        }

        tbody.appendChild(tr);
    });

    return tbody;
}

function crearPie(item){
    const tfoot=document.createElement("tfoot");
    const tr=document.createElement("tr");
    const td=document.createElement("td");
    const cont=document.createTextNode(item);

    td.appendChild(cont);
    tr.appendChild(td);
    tfoot.appendChild(tr);

    return tfoot;
}