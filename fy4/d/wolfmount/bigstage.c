inherit ROOM;

void create()
{
	set("short", "���̨");

	set("long", @LONG
������һ��ܴ����ʯ���γ���һ����Ȼ�Ŀ���ƽ̨��ԶԶ��ȥ��ǰ����ɽ��
�Σ����͵��֣�������ɽ����˵��ɽ�кܶ��ǣ����´��СС������ĸĸ����ʽ��
�����ǣ����Ǵ���ɽ���ģ��ȵ����ǽ�����ʱ��Ҳ��Ҫ����ɽȥ���������и���
�߹پ�����������ɽȺ���Ǳ�Ȼ�ڴ�ȼ�����̣���ӵ����ɱ��Խ����
LONG);

	set("type","road");
	set("exits",([
		"southup":__DIR__"18pan4",
		"eastdown":__DIR__"yinroad3",
		"westdown" : AREA_GUANWAI"shudao2",
	]) );
	set("outdoors", "wolfmount");
	set("objects",([
		__DIR__"npc/fwolf":1,
		__DIR__"npc/fwolfa":1,
    	]) );
    	set("type", "road");
	set("coor/x",-20);
	set("coor/y",70);
	set("coor/z",-50);
	setup();
}

int valid_leave(object me, string dir)
{
    	object ob;
        if( userp(me) && dir=="southup" && ob=present("fighter wolf", this_object()) ) 
        {
                if( me->query("class") != "wolfmount" && !me->query_temp("marks/��ɽ�ο�") )
                {                
                        return notify_fail(ob->name()+"������סȥ·��˵�����������˵Ȳ�������������ɽ������\n");
		}			
	}
	return 1;
}
