// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
�ѽӽ�ɽ�ţ�����һ�磬��ǧ���ز������ܵİ�����Χ�ڵ��У�����������
֮�У����������ޱȣ��ʴ�����������ÿ�������ɹ�ӯ���������˱ǡ��˼����ɲ�
��Ϊ�����ˣ������˲�Զǧ����Ʒ�����г��ϵ��Ƶ��ɲ衣ÿ�괺�������������
�����أ�����Ҫ��������ɨ��������������ࡣ
LONG
        );
        set("exits", ([ 
  "northup" : __DIR__"lianhua",
]));
	set("coor/x",65);
	set("coor/y",19);
	set("coor/z",-20);
	set("objects", ([
                __DIR__"npc/lama2" : 1,
        ]) );
	setup();
        replace_program(ROOM);
}
