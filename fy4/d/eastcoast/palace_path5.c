
inherit ROOM;

void create()
{
        set("short", "�ƺ�����");
        set("long", @LONG
�ƣ������ڽ��£����İ��Ĳ��ˣ�������������ˮ������˷����ޱ��޼ʡ���
�������һ���������ƺ���Ư������֪����ˮ���������Ǵ����ߡ������ߣ����ճ�
֮�ߣ����Ǵ�˵�е����ص�[33m�������ȡ�[32m����������һ��С·,����������ͨ��Զ����
LONG
        );
        set("exits", ([ 
		   "northeast" : AREA_PALACE"entrance",
		   "southdown" : __DIR__"troad0a",
		   "westdown"  : __DIR__"palace_path4",
	]));
        set("outdoors", "palace");

	set("coor/x",260);
	set("coor/y",0);
	set("coor/z",40);
	setup();
        replace_program(ROOM);
}

