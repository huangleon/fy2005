inherit ROOM;
void create()
{
        set("short", "�������");
        set("long", @LONG
���������ϣ����̽�ϡ�����Զ�Ȳ��ϱ������ϱ���������֣������Х����
�������û�˽��еļ��������ӡ��Զ���ڳ����ģ���һƬ�ޱ��޼ʵ�ԭʼɭ�֡�
ż�����п��̽�Ӷ�������˵����ɭ�ֱ���Ե�������ĸۿڡ�
LONG
        );
        set("exits", ([ 
  		"north" : __DIR__"sroad1",
  		"south" : AREA_MANGLIN"edge2",
]));
        set("outdoors", "fengyun");
	set("coor/x",0);
	set("coor/y",-570);
	set("coor/z",0);
	setup();
}

