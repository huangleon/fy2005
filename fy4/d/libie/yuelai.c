// Room: yuelai.c --- by MapMaker
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "������ջ");

	set("long", @LONG
������С�س������Ŀ�ջ�ˣ�����Ҳ���¸ǵģ���ǰ����ȴͻȻ����������
���Ӱ�¥�ϵ��׼�����װ����һ�顣��ջ�ϰ�Ҳ������ʾ�ܲ����͡�˽�����ϰ�͸
����Ϣ˵��һ�н�������Ϊ��Ϯһ�Ⱥ������С��үҪ��¥���¸ǵġ������ס
һ���ϡ�
LONG);

	set("type","house");
	set("exits",([
		"up":__DIR__"corridor",
		"north":__DIR__"stoneroad2",
	]) );

        set("objects", ([
                __DIR__"npc/owner": 1 ]) );

        set("indoors", "libie");
	set("coor/x",-10);
	set("coor/y",-10);
	set("coor/z",0);

	setup();
}
	

int valid_leave(object me, string dir)
{
    object ob,cloth;
        if( dir == "up" && ob=present("lao ban", this_object()))
        {
        	cloth=present("waiter cloth",me);
        	if(objectp(cloth))
        	if(cloth->query("equipped"))
        		return 1;
        	        		
         	return notify_fail("�ϰ�˫��һ�ŵ�סȥ·�������������" 
         		+ RANK_D->query_rude(this_player()) + "��������˰������˵�С��ү�ǻ��˵ã�\n");
    	}
        return 1;
}