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
		"west" : __DIR__"garden2",
		"east": __DIR__"corridor5",
	]));
        set("outdoors", "taiping");
	set("item_desc", ([
	        
	]));
	set("coor/x",-90);
	set("coor/y",-60);
	set("coor/z",0);
	set("map","taiping");
	setup();
}
