inherit __DIR__"no_killing_place";
void create()
{
	set("short", "���");
	set("long", @LONG
��ǰ�Ǽ�����Ϊ��ͨ�Ĵ��ᣬ����С������������׷����֣���ֻ�ʷʵĴ��
�죬�����������쳤�˲��Ӹ¸µĽУ��ƺ�������Ȼ�ҵ����������ÿ��Ϧ��
���µ�ʱ�򣬺���é��ձ�ɵ��ݶ���ᱻ�����Ĵ�����ס����������������һ��
���˵��׷�����ζ��
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
   		"south" : __DIR__"road2",
   		"west" : __DIR__"farm1",
   		"east" : __DIR__"farm2",
   		"north" : __DIR__"nongjia1",
   	]));

   	set("objects", ([
		__DIR__"npc/kid": 2,
   	]) );

	set("no_magic", 1);
   	set("outdoors","taoyuan");
	set("coor/x",10);
	set("coor/y",10);
	set("coor/z",0);
	setup();
        replace_program( __DIR__"no_killing_place");
}


