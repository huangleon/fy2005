
inherit ROOM;

void create()
{
        set("short", "�����");
        set("long", @LONG
������ڻ�ɽ�Ϸ��������Ϊ��ʯ��һ��Ȼʯ�����ʲ������Σ�ˮ��Լһ�ף�
ˮɫ�峺���Դ���ɫ����ˮ�Բ�ӯ�磬�����Ľߣ�����̾Ϊ���졣վ�ڳرߣ�����
�������ƽ�����ߣ����ֿɼ���
LONG
        );
    set("exits", ([ 
  		"south" : __DIR__"yanluo",
	]));
	set("objects", ([
		__DIR__"npc/yu": 1,
	]));
   
    set("outdoors", "huashan");

	set("coor/x",-45);
	set("coor/y",-58);
	set("coor/z",40);
	setup();
    replace_program(ROOM);
}

