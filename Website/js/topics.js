$(document).ready(function(){
    
    $(".clickable").mouseenter(function(){
        var status = $(this).attr('id');
        var number = status.charAt(4);
        var divID = "#flip";
        var divID = divID.concat(number);
        $(divID).css("background-color", "#8182e0"); //lighter #33353e
    });
    $(".clickable").mouseleave(function(){
        var status = $(this).attr('id');
        var number = status.charAt(4);
        var divID = "#flip";
        var divID = divID.concat(number);
        $(divID).css("background-color", "#2a2b30"); //darker #2a2b30
    });
  
    $(".clickable").click(function(){
        var status = $(this).attr('id');
        var number = status.charAt(4);
        var flip = "#panel";

        var flipper = flip.concat(number);
        $(flipper).slideToggle("slow");
    });
    
});