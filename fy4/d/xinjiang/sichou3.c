inherit ROOM;
void create()
{
        set("short", "���ӹʳ�");
        set("long", @LONG
�˳�λ���Ŷ����ι��У�ϵ��������ʮ��������ʦǰ�����Ĺʳǣ��óǽ�����
�����ϸ�ʮ���ɵĻ���̨���ϣ����±���������������Ȼ�����ӳǽ��ж��ź�����
�������š����ڳǽ��������ϣ���������ǽ�����������ʽ�������������������ݡ�
����������Ҫͨ�����С�һ���ذ������Ī�򡱵�ɽ�ڡ�����ΡȻ�����ڵ��ͱ�
�ϣ���Ϊ���ھ�������ˮ���Ż���
LONG
        );
        set("exits", ([ 
  		"northwest" : __DIR__"sichou2",
  		"eastdown" : __DIR__"tulufan",
]));
        set("objects", ([
        	__DIR__"npc/bird" : 2,
                        ]) );
        //set("no_pk",1);
         
        set("outdoors", "xinjiang");
	set("coor/x",50);
	set("coor/y",-50);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
