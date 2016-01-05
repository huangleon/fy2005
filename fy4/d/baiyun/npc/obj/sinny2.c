inherit ITEM;

void create()
{
    set_name("²õÒÂ¼ã", ({ "paper"}) );
	set_weight(350);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        	set("unit", "ÕÅ");
	}
	::init_item();
}
/*
 
               (\~~~/)            
               ( £®£®)        

               (_____)~£®      
   
¡¡¡¡¡¡¡¡¡¡¡¡¡¡- FengYun - ¡¡¡¡¡¡
¡¡¡¡¡¡¡¡¡¡¡¡annie 10.2003
¡¡¡¡¡¡dancing_faery@hotmail.com
*/
