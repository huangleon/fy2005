inherit ROOM;

void create()
{
        set("short", "�����");
        set("long", @LONG
һ���ƻ�ͨ���ĳ��ȣ��ƺ�ԭ�ȱ��Ƿ����Ľֵ���������һЩ��Ժ��լ������
�����ռ�����¥���ĵ��������󣬱㽫���СС����լ���ݸĽ����Թ����¾�ɫ
������ʹ��������ʮ�����Լ��ڶ��������˺�һ�����˾�ס��
LONG
        );
        set("exits", ([ 
		"north" : __DIR__"southstrt",
		"south" : __DIR__"southtower",
	]));
        set("indoors", "loulan");

	set("coor/x",0);
	set("coor/y",-30);
	set("coor/z",0);
	setup();
}
