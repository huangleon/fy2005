// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "���µ�");
        set("long", @LONG
���ڱڻ����������ȭ�ױڻ��������ֳ�ȭ�׵�������й������������
���ڻ���ȭ���ڻ����ϱ�����е���򣬻���ʮ����ɮ�������Ĺ��¸��������ĺ���
��Щ�ڻ����ڳ�ѧ�����书������˵���൱�а����ġ�
LONG
        );
        set("exits", ([ 
  "west" : __DIR__"qianfe",
]));
        set("objects", ([
                __DIR__"npc/monk_float" : 2,
       ]) );
	set("coor/x",10);
	set("coor/y",20);
	set("coor/z",20);
	setup();
        replace_program(ROOM);
}
