// Room: dufang2.c --- by MapMaker

inherit ROOM;

void create()
{
	set("short", "ƫ��");

	set("long", @LONG
���ﱾҲӦ���ǽ������������������ĵط���������ȴ�յ�����û�����ˣ�ֻ
����������ȥ���ر�������еػ���������һ�����У�һ����ʿ������һ������š�
�������˲��������ĵģ�������û����ע��������������һ�����飬���������дʣ�
���������ʿ�����ۣ�˫�ֺ�ʮ����Ȼ�������������������ֶ��ű��ƣ�����
���ű��飬������ҡͷ���ԣ������ζ��
LONG);
	set("type","indoors");
	set("exits",([
	"east":__DIR__"dufang1",
	]) );
	//}}
	set("coor/x",-5);
	set("coor/y",0);
	set("coor/z",0);
        set("indoors", "shanliu");
	set("objects", ([
	__DIR__"npc/xiucai"  :1,
	__DIR__"npc/taoist1"  :1,
	__DIR__"npc/monk1" :1,
        ]) );
	setup();
	replace_program(ROOM);
}
