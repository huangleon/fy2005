inherit ROOM;

void create()
{
	set("short", "�𸮴���");

	set("long", @LONG
һ�߽����Ӿͻ����ȿ����𸮴����ϵ��Ż���ԭ���⾹���ûƽ����ɵģ�����
��ͭʨ��Ҳ���˲��͹��Ľ��ᣬ����һ�գ����ν������䣬�ſ���һ�����
�ܴ������ϼ�޻����ӵ��ŷ���ƤЦ�ⲻЦ�������������Ͽ����㡣
LONG);
	
	set("type","house");
	set("exits",([
		"north":__DIR__"shilu4",
		"southeast":__DIR__"jinlin",
		"southwest":__DIR__"jinyuan",
	]) );
        set("objects", ([
                __DIR__"npc/guard":     1,
        ]));
	set("coor/x",50);
	set("coor/y",60);
	set("coor/z",0);
	setup();

}
int valid_leave(object me,string dir)
{
        if ( (dir=="southwest"||dir=="southeast") &&  present("jin guard", environment(me)))
        	return notify_fail("�ŷ�������ס�����ȥ·���ȵ�����˧������Ϣ�������˵�һ�ɲ�����\n");
        return ::valid_leave(me,dir);
}
