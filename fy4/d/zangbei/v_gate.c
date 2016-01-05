inherit ROOM;
#include <ansi.h>

string gate();
void self_heal();

void create()

{
        set("short", "����կ");
        set("long", @LONG
���ֺ�Ȼ��һ��ɽկ����ɽ�ƶ����������վ������������Ⱦ޴��ľ�ţ�ľ
���ϵ�����ÿ������һ�߷�Բ��������ͭƤ��կ�������Ǹ��ʵ�կǽ�����˶��
��կǽ��ÿ��ʮ���߾���һ����¥����¥�����㣬ÿ�������ף�������Լ�ɿ���
��ոո�ļ�ʸ����ǿ�˾ۼ�������կ���˵��Ǹ������ѹ�֮�ƣ��ѹֹٱ�����Χ��
�������顣
LONG
        );
        set("exits", ([ 
		"northwest" : __DIR__"forest4",
	]));
        set("objects", ([
	]) );
	set("item_desc", ([
		"gate": (: gate() :),
		"door": (: gate() :),
		"ľ��": (: gate() :),
		"կ��": (: gate() :),
	]));
	set("outdoors", "zangbei");
        set("total",100);
        set("coor/x",-1540);
        set("coor/y",600);
        set("coor/z",0);
	set("map","zbwest");
	setup();
}

void 	init(){

	add_action("do_ram","ram");	
	if (query("total")<100) call_out("self_heal",10);

}

void 	reset(){
	::reset();
	delete("exits/south");
}

string gate() {
	int integrity;
	string msg;	
	integrity=query("total");
	msg="���Ⱦ޴��ľ�ţ�������ͭƤ��";
	if (integrity<1) msg +="���Ѿ���ײ���ˡ�\n";
		else {
			msg +="�ŵļ�ʵ��������"+(string)integrity+"����\n";
			msg +="��������ȥ��Ψһ�취���ǰ���ײ���ˣ�������\n";
		}
	return msg;
}


int 	arrow_out(object me) {
	
	string *rooms = ({__DIR__"e_wall1",__DIR__"e_wall2",__DIR__"e_wall3",__DIR__"w_wall1",
		__DIR__"w_wall2",__DIR__"w_wall3"});
	int i;
	object archer_room,g_room,archer;
	
	message_vision(WHT"կǽ��һ�����������˵�������ż���������\n"NOR,me);
	for (i=0;i<sizeof(rooms);i++){
		archer_room=find_object(rooms[i]);
		if (!objectp(archer_room)) archer_room=load_object(rooms[i]);
		if (!archer=present("archer",archer_room)) continue;
		message_vision(HIR"ֻ���ಷ�����һ֧������$N�����䵽������\n"NOR,me);
		if (random(me->query_skill("perception",1)) < 100)
			me->receive_wound("kee",random(me->query("max_kee")/10),archer);
		message_vision(HIR"ֻ���ಷ�����һ֧������$N�����䵽������\n"NOR,me);
		if (random(me->query_skill("perception",1)) < 100)
			me->receive_wound("kee",random(me->query("max_kee")/10),archer);
	}
	 COMBAT_D->report_status(me);
}		
		

	

int	do_ram(){
	object me=this_player();
	
	if (me->is_busy())
		return notify_fail("��������æ��\n");
	if (me->query("str")<30)
		return notify_fail("�������̫С��������ײ��կ�ţ�����ֻ������취�ˡ�\n");
	if (!present("stump",me))
		return notify_fail("��û�п�������ײ�ŵ����ߡ�\n");
			
	message_vision(YEL"$N�þ�ȫ��֮�����������е���׮��կ��ײȥ��\n"NOR,me);
	me->start_busy(3);
	add("total",-2);
	if (query("total")>0) {
		message_vision(YEL"ֻ��կ�ź�����죬�ƺ��ɶ���Щ��\n\n"NOR,me);
		call_out("arrow_out",2,this_player());
	}	else {
			message_vision(WHT"��¡һ�����죬�̳����죬կ�ŵ�����ȥ��\n\n"NOR,me);
			set("exits/south",__DIR__"village");
		}
	if (remove_call_out("self_heal")==-1) call_out("self_heal",10);
	return 1;
}
	

	
void self_heal() {
	if (query("total")<0) set("total",0);
	if (query("exits/south")) delete("exits/south");
	if (query("total")<95 && query("total")>=0) {
		add("total",5);
		call_out("self_heal",10);
	}
}

