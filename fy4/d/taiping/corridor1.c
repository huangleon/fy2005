// seaside.c
inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
һ·������ˣ�Ժ�ӱ�ֲ������ȴ�ѵ��㣬������ϡ�Σ����������ġ����ֻ
�л��㣬ֻ�г�����Ī˵������Ӱ����������û�У������ĸ��������ƽ�����մ�
�ྶͥ��̧ͷ��ȥ������һ�������εĴ���ɹ�������������������
LONG
        );
        set("exits", ([ 
		"south" : __DIR__"yard",
		"west": __DIR__"corridor2",
	]));
        set("outdoors", "taiping");
	set("item_desc", ([
	        
	]));
	set("coor/x",-70);
	set("coor/y",-40);
	set("coor/z",0);
	set("map","taiping");
	setup();
}
