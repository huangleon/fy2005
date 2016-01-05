// waterskin.c
#include <login.h>
inherit ITEM;
inherit F_LIQUID;
string *revive_loc= ({
    AREA_FY"church",
    AREA_GUANWAI"tower",
});

void create()
{
	set_name("ţƤ�ƴ�", ({ "jiudai", "dai" }) );
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ��ţƤ��Ĵ�ƴ������װ�ðˡ������ľơ�\n");
		set("unit", "��");
		set("value", 20);
		set("max_liquid", 15);
	}

	// The liquid contained in the container is independent, we set a copy
	// in each cloned copy.
	set("liquid", ([
		"type": "alcohol",
		"name": "������",
		"remaining": 5,
		"drunk_apply": 6,
	]) );
	::init_item();
}

/*
int do_drink(string arg){
	object me, cloth;
   	int foo;
   	foo=::do_drink(arg);
   	if (!foo) return foo;
   	me = this_player();
	if(query("liquid/name") != "������"){
		return foo;
	}
   	if(me->is_ghost()){
		me->reincarnate();
		cloth = new("/obj/armor/cloth");
		if(objectp(cloth)) {
			cloth->move(me);
			cloth->wear();
		}
		me->move(revive_loc[random(sizeof(revive_loc))]);
		me->set("startroom", base_name(environment(this_player())));
		message("vision",
                "���Ȼ����ǰ�����һ����Ӱ����������Ӱ�ֺ����Ѿ�������\n"
                "�ܾ��ˣ�ֻ����һֱû������\n", environment(me), me);

   }	
  return 1;
}

*/