#include <ansi.h>
inherit ITEM;
string statuedesc();

void create()
{
    set_name("����", ({"statue","����"}) );
    set_weight(200000);
    set("long", "һ�����˸ߵ�������һ���ִ�ŵ���׺��ӣ�������ī���Ũü�������ȧ
�ǣ�һֻ�ݹ���᾵Ĵ���ץ�ű�����ÿ��õ�������\n");
    set("no_get",1);
    set("no_shown",1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
            	set("long",(: statuedesc :));
                set("unit", "��");
                set("value", 3000);
              }
    ::init_item();
}

void init()
{
	add_action("do_turn","turn");
	add_action("do_look","look");
}


int do_look(string arg){
	
	if (arg=="����" || arg == "����") {
		tell_object(this_player(),"��Ŀ��õ�������������İ���Ҳ��ȱ�ˡ�\n");
		return 1;
	}
	return 0;
}


int do_turn( string arg){
	object me, room;
	
	me=this_player();
	if (!REWARD_D->check_m_success(me,"ħ��Ѱ��")) {	
		// ���˿ߡ�is not finished right now. no riddle gives this mark
		tell_object(me,"��ʹ��ת��ת���֣�ȴ�Ҳ�������Ҳûʲô��Ӧ��\n");
		return 1;
	}
	
	if (!arg || (arg!="����" && arg!="handle")) {
		tell_object(me,"��Ҫתʲô��\n");
		return 1;
		}
	message_vision	(YEL"$N����һ�⽣����ֻ��һ��¸µ�������$N���³�����һ���󶴡�\n"NOR,me);
	room = find_object(AREA_EREN"tocave");
    if(!objectp(room)) 
      	room = load_object(AREA_EREN"tocave"); 
	message_vision(HIR"һ�����У�$N����ֱ׹��ȥ��\n"NOR,me);
	message("vision",HIG"�Ϸ��ֵ���һ����������æ���ҵ�ץס������ߵ�������\n"NOR,room);
	me->move(room);
	return 1;
}