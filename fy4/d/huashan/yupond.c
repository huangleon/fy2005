
inherit ROOM;

void create()
{
        set("short", "��Ȫ��");
        set("long", @LONG
������һ����Ȫ������Χ�԰ײ��ᣣ��Ա߻��ڷ��ż������Ρ�Ȫ�۲�����
�ܵ���ʯ��ˮ��ϴ�Ĺ��ɾ���Ȫˮ����͸����ɫ����Ȫ�ϲ���ð���İ�ɫˮ���
����������һƬ����֮�С�
LONG
        );
    set("exits", ([ 
  		"south" : __DIR__"path1",
	]));
   
    set("outdoors", "huashan");

	set("coor/x",-10);
	set("coor/y",20);
	set("coor/z",-10);
	set("objects", ([
                __DIR__"npc/nakedman" : 1,
				__DIR__"npc/nakedman2" : 1,
      ]) );
	setup();
	replace_program(ROOM);
}

