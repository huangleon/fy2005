inherit ROOM;

void create()
{
	set("short", "�Ǳʷ�");

	set("long", @LONG
ɽ·��������ͻȻ��������������ɽ������絶���м�����һ��խխ��ɽ·��
�������˲��ܲ�����С�����ν���ƺ�֮���в��ã�Գ����ȳ���Ԯ����������ɽ
���������죬��ͬ�쵶����������ϣ����ϣ����ϣ�����������
LONG);

	set("type","mountain");
	set("exits",([
		"northdown":__DIR__"wolfhill",
		"southwest":__DIR__"wolfslope",
	]) );
       set("outdoors", "wolfmount");
	set("objects",([
            __DIR__"npc/geshu":1,
    	]) );
	set("coor/x",0);
	set("coor/y",30);
	set("coor/z",-10);
	setup();
}

int valid_leave(object me, string dir)
{
    	object ob;
        if( userp(me) && dir=="southwest" && ob=present("zhongli zhan", this_object()) ) 
        {
                if( me->query("class") != "wolfmount" && !me->query_temp("marks/��ɽ�ο�") )
                {                
                        return notify_fail(ob->name()+"����һ����סȥ·�������ȵ����˴�������ɽ�صأ���أ�����\n");
		}
	}
	return 1;
}
