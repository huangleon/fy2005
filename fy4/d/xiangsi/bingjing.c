// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ROOM;
string tree();

void create()
{
	set("short", "������");
        set("long", @LONG
��Խ��խ�ķ�϶��������һ��ֻ����ƺ������ССƽ̨��ƽ̨������ȣ�
������񷣬ռ����һɽ�ķ�ɫ��ƽ̨�ĵ���ӡ��һȦǳǳ�İ��ۣ����һ����
�µ���״��һ�����������ڰ��۱�Ե�����������֮�⣬�����°���һ��ʯ��
��ʯ�����ߺ�������̺���Ȼ��
LONG
        );
	set("objects", ([
		__DIR__"npc/master" : 1,
		__DIR__"obj/pinetree" : 1,
		__DIR__"obj/go" : 1,
	]));

		set("item_desc", ([
		"flower" : (: tree :),
		"С��" : (: tree :),
		"�׻�" : (: tree :),
		"�ݴ�" : (: tree :),
		"grass" : (: tree :),
		"��" :  (: tree :),
		"����" :  (: tree :),
		"��" :  (: tree :),
		"tree" :  (: tree :),
		"pine tree" :  (: tree :),
		"pine" :  (: tree :),
	]) );   

	set("exits",([
  		"northdown" : __DIR__"leidashi",
	]) );

	set("outdoors", "xiangsi");

	set("coor/x",10);
	set("coor/y",-10);
	set("coor/z",10);
	setup();
}


string tree()
{
	object me;
	int i;
	me = this_player();
	i = NATURE_D->get_season();
	if(i != 1 && i!=3) {
		tell_object(me, "����ҡҷ���˵�С������������������\n");
	} else  if (i==1)
	{
		tell_object(me, CYN"\n����ҡҷ���˵�С������������������\n"NOR);
		if(query("flower_amount") > 0) {
			tell_object(me, HIW"���м����ż���Ĵָ��С�İ׻������ŵ������㡣\n"NOR);
			add_action("do_pick", "pick");
		}
	}
	else if (i==3)
	{
		tell_object(me, CYN"\n����ҡҷ���˵�С������������������\n"NOR);
		if(query("dinecone_amount") > 0) {
			tell_object(me, HIC"�ݴ����ƺ���ʲô����������\n"NOR);
			add_action("do_search", "search");
		}
	}
	return "";
}

int do_pick(string arg)
{
	object me, flower;
	me = this_player();
	if(!arg || (arg != "flower" && arg != "�׻�" && arg != "С��")){
		return 0;
	}
	if(query("flower_amount") > 0) {
	message_vision("$N����ժ����һ���ɫ�Ļ��䡣\n", me);
	flower = new(__DIR__"obj/flower");
	flower->move(me);
	add("flower_amount", -1);
	return 1;
		}
else	
return 0;
}

int do_search(string arg)
{
	object me, flower;
	me = this_player();
	if(!arg || (arg != "grass" && arg != "�ݴ�" && arg != "��")){
		return 0;
	}
	if(query("dinecone_amount") > 0) {
	message_vision("$N�ڲݴ�������һ�����ͳ���һö�ɹ���\n", me);
	flower = new(__DIR__"obj/dinecone");
	flower->move(me);
	add("dinecone_amount", -1);
	return 1;
		}
else	
return 0;}

void reset(){
	::reset();
	set("flower_amount", random(4));
	set("dinecone_amount", random(4));
}

/*
�X[ ��- FengYun -�� ]���������[
��[dancing_faery@hotmail.com]�������[
��[ ��annie 09.2003�� ]�������a    ��
��[ ������������¶������ʱ������˪ ��
�^��������������������������������-�a
*/
