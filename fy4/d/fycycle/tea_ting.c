inherit ROOM;
void create()
{
        set("short", "��ͤ");
        set("long", @LONG
����һ����׵Ĳ�ͤ��ר�Ź�������·��Ъ���á���ͤ������������Ӻͼ�ֻ
���ӡ���ʨ�ھֵ��ڳ���������������Ҫͣһͣ���������˵��������ʦ�ȿ�ˮ��
��Ҳ��Ϊ��ˣ�����Ҳ��ɽ���ٷ�����ϲ����˵ĵط���
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
		"south" : __DIR__"road2",
	]));
        set("objects", ([
        	__DIR__"npc/xiaofan": 1,
                     ]) );
        set("outdoors", "fengyun");
	set("coor/x",-200);
	set("coor/y",220);
	set("coor/z",0);
        setup();
    
}
