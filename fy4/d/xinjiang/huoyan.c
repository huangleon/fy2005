inherit ROOM;
void create()
{
        set("short", "����ɽ");
        set("long", @LONG
����ɽ��ʮ���ɽͷ�������ٺ�ɫ�������յ���ҫ�£�����ȼ���ŵ����ܴ��
��������ɽ�����ڴ�ɽ���γ��и����ϵĴ�˵����ʱ����ɽ��һ������������ͯ
��ͯŮ��һλ�й�����׿��������Ľ�������������ִ�������������ս������ҹ��
������ն�˶��������Ѷ���ն��ʮ��ء��������ٲ��������һ����ɽ����ն����
����˻���ɽ�е�Ͽ�ȡ�
LONG
        );
        set("exits", ([ 
  "westdown" : __DIR__"butao",
  "southeast" : __DIR__"sichou4",
  "east" : __DIR__"qianfo",
]));
        set("objects", ([
        __DIR__"npc/huwaiter" : 1,
                        ]) );
        //set("no_pk",1);
        
        
        set("outdoors", "xinjiang");
	set("coor/x",90);
	set("coor/y",-50);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
