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
		"east" : __DIR__"saintpalace",
		"west" : __DIR__"weststrt2",
]));
        set("indoors", "loulan");

	set("coor/x",-10);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}
