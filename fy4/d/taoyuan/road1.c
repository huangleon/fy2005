inherit __DIR__"no_killing_place";
void create()
{
	set("short", "����ʯ��·");
	set("long", @LONG
����ʯ��·��ɽ�ּ�ı������ʪ���������͵����Ź⣻ʯ������̦����
�������˷�϶��ÿһ��ʯ����������Ϻõ�������˱ߡ�ʯ��·�ı��������ɢ��
�ż���ũ�ң�ÿ���Է�ʱ�䵭���Ĵ����������Ʈ���ּ䡣
LONG
);
	set("exits", ([ /* sizeof() == 4 */
		"north" : __DIR__"fhome",
		"west" : __DIR__"taovillage",
   		"south" : __DIR__"teaplace",
   		"east" : __DIR__"road2",
	]));
	set("no_magic", 1);
   	set("outdoors","taoyuan");
	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
    replace_program( __DIR__"no_killing_place");
}
