
inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
����һ�����ӵ����磬����͸��ï�ܴ��̵���Ҷ���·�Ⱦ���˵�������ɫ��
һ��СϪ�����ĵش�����Ƭ���֣��ƺ�����ˮ�������ƻ����������������������
ȴ�˽������ն����������������
LONG
        );
        set("exits", ([ 
  "south" : __DIR__"bamboo3",
  "north" : __DIR__"bamboo",
]));
        set("outdoors", "palace");
        set("resource/water",1);
         set("liquid/name","����Ϫˮ");
	set("coor/x",40);
	set("coor/y",30);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}

