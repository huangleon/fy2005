//Created by justdoit at May 2001 
//All Rights Reserved ^_^

inherit ROOM;
void create()
{
        set("short", "��������¥");
        set("long", @LONG
�˼��ǰ��Ƴ��д������¥�һ�����������Ļ������������ȣ������ü�����
���¡�¥�ڵ�����������ڻԻͣ�����������ˣ��޲�������䣬Զ��ǧ������Ͻ�
�Ǵ��Ҳ������ˡ���¥�ڰ���������챦����������Ĺ�����ȸ���������Ŀ��
LONG
           );
        set("exits", 
           ([ 
       "west" : __DIR__"skystreet",
	    ]));
	set("objects", 
	   ([ 
       __DIR__"npc/yexingshi" : 1,
	    ]));
        set("indoors", "baiyun");
	set("coor/x",0);
	set("coor/y",-1030);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
