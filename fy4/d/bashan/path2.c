#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "��ɽС��");
        set("long", @LONG
ǰ���ǲݴԺ���ľ�������Ƿǳ�ïʢ����ͩľ��С·���Գ����˸�ɫ˵����
���ֵ����޵Ļ���������յ���ͩ���£���᫲�ƽ����С·ӳ��һ��ɭɭȻ�ĸ�
������ͩ��֦Ҷ��ïʢ����ȫ�ڱ�����ͷ������գ�ʹ·������һƬŨ�صĺڰ���
���ԲԲ��С������Ȼ�ڵ��ϳ�Ƭ�ĳ��֣���Ѹ�ٵ���ʧ������֦Ҷ�ķ�϶��©
�µĹ��ߡ�
LONG
        );
	set("exits",([
  		"west" : __DIR__"path3",
  		"east" : __DIR__"path1",
	]) );
/*	set("objects", ([
	__DIR__"npc/wall" : 1,
					]) );*/
	set("no_fly",1);
	set("coor/x",-60);
	set("coor/y",220);
	set("coor/z",50);
	set("outdoors", "bashan");
	setup();
}

int init()
{
	add_action("do_hide", "hide");
	add_action("do_comeout", "comeout");
	if (!query("wall"))
	{
		set("wall",1);
		new(__DIR__"npc/wall")->move(this_object());
	}
	if (userp(this_player()))
	{
		add("count",1);
		if (query("count") == 2)
			call_out("attack",1,this_player());
	}
}

int attack(object ob)
{
	if (environment(ob) == this_object())
		message_vision(CYN"��ͻȻ��������������÷���ï�ܣ�������Խ�������(hide)��\n"NOR,ob);
	return 1;
}

int do_comeout(){
	object me;
	mapping who;
	int i,j,amount;
	
	me = this_player();
	if(me->query_temp("condition_type") != NOR CYN" <��������>"NOR)
		return 0;		

	message_vision("$N�������ת�˳�����\n", me);
	delete("hide");
	me->delete_temp("condition_type");
	return 1;
}

int do_hide(){
	object me;
	mapping who;
	int i,j,amount;
	
	me = this_player();
	if(me->query_temp("condition_type") == NOR CYN" <��������>"NOR)
		return  notify_fail("���Ѿ���������ѽ����\n");		

	if (query("hide"))
		return  notify_fail("����߲ز�����ô���ˣ�����\n");		

	message_vision("$Nת�������ȥ���������Ρ�\n", me);
	tell_object(me,"�����û�ж�ر�Ҫ��ʱ�򣬿�����comeoutָ���뿪��\n");
	set("hide",me);
	me->set_temp("condition_type",NOR CYN" <��������>"NOR);
	return 1;
}

int valid_leave(object me, string dir)
{
	if (me->query_temp("condition_type") == NOR CYN" <��������>"NOR)
		return notify_fail("������������ߣ����ǲ�Ҫ����Ϊ�\n");
	if (present("wall of blossoms",this_object()) && dir == "west")
		return notify_fail("�������ĵ�·��һ�»�ǽ�赲ס�ˡ�\n");
	return 1;
}

/*
�X[ ��- FengYun -�� ]���������[
��[dancing_faery@hotmail.com]�������[
��[ ��annie 09.2003�� ]�������a    ��
��[ ������������¶������ʱ������˪ ��
�^��������������������������������-�a
*/
