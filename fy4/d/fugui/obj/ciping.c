inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("���ƿ", ({ "ping", "ƿ" }) );
	set_weight(70);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ�����ƿ��\n");
		set("unit", "��");
		set("value", 100);
		set("max_liquid", 1);
	}

	set("liquid", ([
		"type": "water",
		"name": "�������Ľ�ҩ",
		"remaining": 1,
		"drunk_apply": 1,
	]) );
	::init_item();
}

int do_drink(string arg)
{
   
	object me;
	me=this_player();
   	
   	if(arg=="ping" || arg=="���ƿ" || arg == "ƿ" || arg == "bottle") {
	   if (query("max_liquid"))
	   {
	        message_vision("$N�����ƿ��Ľ�ҩһ��������ȥ��\n",me);
			me->change_condition_duration("redsnake",0);
			set("max_liquid",0);
			set("liquid/remaining",0);
			me->unconcious();
	 		set("value",0);
	 		return 1;
	   } else { 
	   		tell_object(me,"ƿ�����Ѿ��ǿտ���Ҳ�ˡ�\n");
	   		return 1;
	   }		
 	}
}

int do_fill(string arg) {
	if(arg=="ping" || arg=="���ƿ" || arg == "ƿ" || arg == "bottle") {
		tell_object(this_player(),"ƿ��̫С��ʲôҲ�಻��ȥ��\n");
		return 1;
	}
	return 0;
}