inherit ROOM;
void create()
{
        set("short", "�䳡");
        set("long", @LONG
�䳡���϶��뱱��ңң��ԣ���ƽ���µ��Ӷ��ڱ������Ṧ�����̣���������
��ʽ�����ı��У���Ȼ�õ����Ļ��ǽ����䳡��ǽ���Ļ���������һ�����ñ���
�ļ��ӣ�ƽ���е�������ʱ�����������ʮ�˰���У�������ȴ�Եÿտյ�����
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"wuchang1",
]));

   	set("outdoors","qingping");
	set("coor/x",-60);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
	
	replace_program(ROOM);
}
