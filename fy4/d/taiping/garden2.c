inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
������Ժ����Ҷ������Ժ�������м��ðŽ��������������������������ҹ����
��һ���������ã���������������һ��������λس̣�������Сͥ��ң���
��ǧ���⣬���飬һ���贰һ���ơ������������ʽ����飬��������Ʊ�ҡҷ�ڷ�
�еİŽ�Ҷ�����ˡ�
LONG
        );
        set("exits", ([ 
		"north" : __DIR__"pavilion",
		"east": __DIR__"corridor4",
	]));
        set("outdoors", "taiping");
	set("item_desc", ([
	        
	]));
	set("coor/x",-100);
	set("coor/y",-60);
	set("coor/z",0);
	set("map","taiping");
	setup();
}
