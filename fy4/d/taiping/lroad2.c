inherit ROOM;
void create()
{
        set("short", "����С��");
        set("long", @LONG
������ɽ��������ʯ���ɵ�·��С���ݺᣬ����ҹɫ�У���ֱ����ͼҲ�ƣ�
��������ׯ԰���˱ط�Ѱ��֮����ֻ�����ڵ������ƺ��Ӳ����ϣ������ǿ�֦��Ҷ��
��ɪ�����ң�����ıܽ��ڰ�����ڻ�����յĻԻ͡�
LONG
        );
        set("exits", ([ 
		"north" : __DIR__"lroad3",
		"south" : __DIR__"lroad1",
	]));
        set("outdoors", "taiping");
        set("no_fly",1);
	set("item_desc", ([
		    
	]));
	set("coor/x",70);
	set("coor/y",-70);
	set("coor/z",0);
	set("map","taiping");
	setup();
	replace_program(ROOM);
}
