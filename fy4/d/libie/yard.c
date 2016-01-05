// Room: yard.c --- by MapMaker
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "СԺ");

	set("long", @LONG
����һ�����������СԺ��һ��˥�ϵİ������Ѿ���ʼ��ή��һ���ƹ������
ǽ�ǣ�ǽ��һ���п�ˮ����Ժ�и���������ʯ�ʣ�һ�����ߴ������ڵ����૵ز�
֪��˵Щʲô��Ժ�����׾���������С�ݣ���ľ�ſ��ţ��紵֮�£��¸����졣
LONG);

	set("exits",([
	"west":__DIR__"nongjia",
	"south":__DIR__"stoneroad",
	"north":__DIR__"neishi",
	]) );
        set("objects", ([
                __DIR__"npc/oldyu": 1,
        ]) );
        set("item_desc",([
        	"well":		"ˮ����ڹ�¡�˵�ʲôҲ�����壨approach?��\n",
        	"��":		"ˮ����ڹ�¡�˵�ʲôҲ�����壨approach?��\n",
        	"������":	"�������߸ߵģ���������ûϣ������ȥ�ˡ�\n",
        	"tree":		"�������߸ߵģ���������ûϣ������ȥ�ˡ�\n",
        	]));	
        set("outdoors", "libie");
        set("yu_home",1);
	set("coor/x",-5);
	set("coor/y",10);
	set("coor/z",0);
	setup();

}


void init()
{
	add_action("do_approach", "approach");
}


int do_approach(string arg)
{
        object me;
        object room;
        me = this_player();
	if(!arg || arg != "��" && arg != "well" ) return 0;
	
	message_vision("$N�߽�ˮ��̽ͷ������ȥ�� \n", me); 
	tell_object(me,"ˮ������ף��������ƺ���������������ˮ�������� \n");
	
	if (REWARD_D->riddle_check(me,"���")<2)	return 1;
        
        room = find_object(__DIR__"well");
	if(!objectp(room)) room=load_object(__DIR__"well");
	
        if (room->usr_in())
        	return notify_fail("��������Ѿ������ˣ�����������˵�ɡ�\n");
        
        tell_object(me,"����������ʧ�ٵ����ã�������ȴ��������ģ�һҧ��������ȥ��\n\n\n");
        
        room->reset();
        room->set("corpse",1);
        me->move(room);
        return 1;
}