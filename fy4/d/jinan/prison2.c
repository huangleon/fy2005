inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
�����Ǽ��ϰ����ŷ�ɥ���ĵ��Σ���˵����ͨǿ��С����������������
���죬��������Σ�Ҳֻ�е������������λ������ظߵ�ˮ������̹ǣ�����
�ϳ��그�˵�Ѫˮ����й���Ѿ�������������а������գ�ֻ�ж���һ˿˿΢
��ʹ�������������
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
//  "northup" : __DIR__"andao2",
]));
        set("objects", ([
        __DIR__"npc/laoqi" : 1,
                        ]) );

	set("coor/x",60);
	set("coor/y",0);
	set("coor/z",-20);
	set("jinan_prison",1);
	set("no_fly",1);
	setup();
        
}
