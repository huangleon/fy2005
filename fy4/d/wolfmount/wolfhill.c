inherit ROOM;

void create()
{
	set("short", "������");

	set("long", @LONG
Ⱥɽһ����������ͷ��������������������ɫ��Ȼ��õͳ���ɬ������ѹ����
������������Զ����ʱ�������������ţ���·��������ޱ��޾�������֮���޷�
���ݡ��������б���һ�򵱹أ����Ī�����Ǳʷ壬������ɽ���Ϻ�Ȼ����������
�¶�������Ҫջ����
LONG);

	set("type","mountain");
	set("exits",([
		"eastdown":__DIR__"cliffroad1",
		"southup":__DIR__"wolfhill2",
		"northdown":__DIR__"18pan1",
	]) );
       set("outdoors", "wolfmount");
	set("objects",([
     		__DIR__"npc/tuoba":1,
    	]) );
	set("coor/x",0);
	set("coor/y",40);
	set("coor/z",-20);
	setup();
}

int valid_leave(object me, string dir)
{
    	object ob;
        if( userp(me) && dir=="southup" && ob=present("tuoba zhan", this_object()) ) 
        {
                if( me->query("class") != "wolfmount" && !me->query_temp("marks/��ɽ�ο�") )
                {                
                        return notify_fail(ob->name()+"����һ����סȥ·�������ȵ����˴�������ɽ�صأ���أ�����\n");
		}
	}
	return 1;
}
