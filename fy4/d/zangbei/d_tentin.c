
inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
����������˿�����յ�����û�У��±��ϣ����������ֱ����˵�������
���յĵط�����������һƬ����������Ĳݵأ�������ȴ���ű������κβݵض���
��ʮ����Ҳ����ʮ���ĵ�ձ����ձ�����ż��Ű��������϶������ʹ��;Ʋˣ��ü�
���������µ��ˣ����������ĵ����ڵ�ձ�ϺȾơ�
LONG
        );
        set("exits", ([ 
	  	"out" : __DIR__"d_tent",
	  	
			]));
	set("objects", ([
		__DIR__"npc/king": 1,
		__DIR__"npc/princess2": 1,
	]));
	set("item_desc",([
		
	]));
        
        set("coor/x",-55);
	set("coor/y",310);
	set("coor/z",0);
	set("map","zbeast");
	setup();
}
