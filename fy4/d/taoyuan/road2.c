inherit __DIR__"no_killing_place";
void create()
{
	set("short", "����ʯ��·");
    set("long", @LONG
����ʯ��·��ɽ�ּ�ı������ʪ���������͵����Ź⣻ʯ������̦����
�������˷�϶��ʯ��·�ı���ɢ���ż���ũ�ң�ÿ��Ϧ�����µ�ʱ��վ�������
�����ŵ����˵���ζ��
LONG
);
	set("exits", ([ /* sizeof() == 4 */
		"north" : __DIR__"nongjia",
   		"west" : __DIR__"road1",
   		"east" : __DIR__"road3",
   		"south" : __DIR__"linjian",
	]));
	set("no_magic", 1);
   	set("outdoors","taoyuan");
	set("coor/x",10);
	set("coor/y",0);
	set("coor/z",0);
	setup();
        replace_program( __DIR__"no_killing_place");
}


