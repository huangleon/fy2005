
inherit ROOM;
void close_path();
void create()
{
        set("short", "�����Ÿ�");
        set("long", @LONG
����ר���д�����������������������������������ģ�����һ��ǧ��ĺ��ͣ�
���Ƕ��Ž����Ĳ���һ�����������䷿�ӵ�����ֻ��һ���ϵȴ����ĥ�ɵİ�������
���Ϸ�����ֻ���ͽ𱭡������ǽ�Ϲ������ֻ���ʣ�µ�һ����һ��һ�����صĺ첼
������
LONG
        );
        set("exits", ([
                "down" : __DIR__"fyge",
		"east" : __DIR__"fysf",
			"north", __DIR__"fysecret",
        ]));

        set("coor/x",10);
        set("coor/y",10);
        set("coor/z",-290);
        setup();
}
