
inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
���µ���ɳͻȻ��������ˬ��΢����������һ��СС�ĺ��������������ǰ��
ˮ��Ȼֻ�ж�ָ��ȴ���峺���������������̲ݷҷ�����Ȼ�ڿ��ȵ�ɳĮ�У���
ˮ������ô�������������һֱ�������Ϳ����ߵ������[33m������[32m����Խ��ɳ���
��������[33m���Ź�[32m��Ҳ����ͨ��[33m�ر�֮��[32m�ıؾ�֮·��
LONG
        );
        set("exits", ([ 
  		"west" : __DIR__"desert9",
  		"north" : __DIR__"sandlin",
  		"east" : __DIR__"desert7",
	]));
	set("objects", ([
		__DIR__"npc/thinlama" : 1,
	]));
	set("resource/water",1);
        set("liquid", (["container": "��"]));
        set("outdoors", "quicksand");

	set("coor/x",-1085);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
}
