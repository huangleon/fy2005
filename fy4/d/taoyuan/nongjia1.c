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
   		"south" : __DIR__"nongjia",
   		"west" : __DIR__"guojia",
   		"north" : __DIR__"farm",
   	]));

	set("no_magic", 1);
   	set("outdoors","taoyuan");
	set("coor/x",10);
	set("coor/y",20);
	set("coor/z",0);
	setup();
        replace_program( __DIR__"no_killing_place");
}


