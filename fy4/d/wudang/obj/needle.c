inherit ITEM;

void create() {
	set_name("����", ({ "needle"}) );	
	set("long", " һ�����롣\n");
	set("unit", "��" );
	set("value", 1);
    if( clonep() )
       set_default_object(__FILE__);

}