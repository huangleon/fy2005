inherit ITEM;

void create()
{
   		set_name( "���ɢ", ({ "mafei san"  }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        	set("unit", "��");
    		set("value",0);
    		set("long","һ��СС����ҩ��\n");
    		set("medman",1);
    		set("real", 1);
    		set_weight(5);
		}
		::init_item();
}