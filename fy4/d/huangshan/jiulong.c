// TIE@FY3 ALL RIGHTS RESERVED
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
���·ת����ǰ��ɫ����һ�䣬һ����ˮ���춼����������壬Ȼ������¯��
�޺���������¾��۶��£�һ��һ̶�����پ�̶����˵�����ÿ�����֮����ˮ
����������������ۣ��۶����ۣ�����ǧ����ڣ�����������裬��̬���
LONG
        );
        set("exits", ([ 
		  "southdown" : __DIR__"mroad1",
  		"northwest" : __DIR__"zhulin",
		]));
    set("item_desc", ([
    	"����": "������Ȼ�����ޱȣ���ʯ��ͻأ��ƽ����������Ŵ�������ȥ��\n",
    	"cliff": "������Ȼ�����ޱȣ���ʯ��ͻأ��ƽ����������Ŵ�������ȥ��\n",
    ]) );
    set("outdoors", "huangshan");
	set("coor/x",-40);
	set("coor/y",30);
	set("coor/z",20);
	setup();
}


void init(){
	add_action("do_climb","climb");
}


int do_climb(string arg){
	object me;
	me= this_player();
	if(!arg || (arg != "cliff" && arg!="up" && arg!="����")){
		return 0;
	}	
	if (me->query_temp("jiulong_climb")) {
		tell_object(me,"���Ѿ����������ˡ�\n");
		return 1;
	}
	message_vision("$Nץס������ͻ����ʯ�飬����С����ȥ��\n", me);
	me->start_busy(2);
	call_out("arrive", 2, me);
	me->set_temp("jiulong_climb",1);
	return 1;
}



int arrive(object me){
	int i;
	object room;
	if (!me)	return 1;
	if (me->is_ghost())	return 1;
	i = me->query_skill("move",1);
	me->delete_temp("jiulong_climb");
	
	if(i < 100) {
		message_vision("$N�ȶ��ӷ�������������ôҲ������ȥ��\n",me);
		return 1;
	} else if(random (5)){
		message_vision("$Nһʧ�֣����������������\n",me);
		me->receive_wound("kee",100);
		me->set_temp("last_damage_from","��ɽˤ���ˡ�\n");
	} else if  (me->query("cps")< 32) {		// 150 chanting + 2 ability if you don't distribute and w/o master
		tell_object(me, "�����أ��㵽�˰�ɽ����
"WHT"���ϰ������ƣ�����Գ�����������Ŷ��͵�ʯ�ڣ��㲻������������\n"NOR);
		tell_object(me,"������������Ҫʵ�ʶ���32�㣩\n");
		message_vision("$N��ͷɥ����������������\n", me);	
	} else if (me->query("kar")< 34) {
		tell_object(me, WHT"Խ���ϣ�ɽ��Խ���վ���������û�����֮�أ�
��ѽ�����ۿ���Ҫ�����ˣ�

��Ȼ����������ס����ʯһ�ɣ���Ȼ���¹�ȥ��

����ҵ��������ץ������̫�ʲô��ûץס��\n\n"NOR);
		message_vision("$N��ɽ����һ�����Դе���������\n",me);
		tell_object(me,"������������Ҫʵ������34�㣩\n");
		return 1;	
	} else {
		room=find_object(AREA_HUANGSHAN"pond");
		if(!objectp(room)) 
        	room = load_object(AREA_HUANGSHAN"pond"); 
		me->move(room);
		message_vision("$N����������������\n",me);
	}	
	return 1;
}
