
inherit ROOM;

void create()
{
	set("short", "��Ȫ");
	set("long", @LONG
������Ҷ֮�䣬һ����Ȫ����ɽ���������������겻�ϡ���˵�У���ͥ����
���������ѱ����������˼䡣�����䵱ɽ�ϣ����ǽ���Ľ�Ȫ����ȪȪˮ��������
��·�˽�ͣפ�ڴˡ���ϢƬ�̣�������ɽ������Ȫˮ���ˣ�����������������У�
����������·��
LONG
	);
	set("exits", ([
		"west" : __DIR__"sansongting",
	]));
	set("outdoors", "wudang");
        set("resource/water",1);
	set("liquid/name","��Ȫˮ");
	set("liquid/type", "water");
	 set("objects", ([
                __DIR__"obj/pestle" : 1,
       ]) );
	set("coor/x",20);
	set("coor/y",-40);
	set("coor/z",10);
	setup();
	replace_program(ROOM);
}
