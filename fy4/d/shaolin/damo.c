// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
    set("short", "��ĦԺ");
    set("long", @LONG
�����Ǵ�Ħ����֮����Ժ�ڳ��輫Ϊ�򵥣�����ǽ�����������������������
����ɮ�뷢�԰ף��������׿�˼������ħ�ʣ�һ����˼���˽���������̻ӱ�����
����֮�ϣ����ӡ֤��
LONG
        );
    set("exits", ([ 
        "east" : __DIR__"xiji",
        "west" : __DIR__"jiangwu",
        "north": __DIR__"cj",
        "south": __DIR__"luohan",
        ]));
    set("objects", ([
        __DIR__"npc/master_18" : 1,
        __DIR__"npc/laomonk" : 2,
        ]) );
	set("coor/x",0);
	set("coor/y",90);
	set("coor/z",20);
    setup();
}

int valid_leave(object me, string dir)
{
    object ob;
    
    	if (ob=present("old monk", this_object()))
	if( userp(me) && dir=="north" 
			&& me->query("vendetta/shaolin")>=1) 
		return notify_fail(ob->query("name")+"�ȵ�:����ֹ��!\n");

    // free pass
    	if (me->query("family/master_id") =="damo") return 1;
    	if (me->query("family/generation")<=18 && me->query("class")=="shaolin") return 1;
    
   
    // to non-shaolin student   
/*    if (dir == "north" && me->query("family/family_name") != "������"){
       	if (ob=present("old monk", this_object()))
    		return notify_fail(ob->query("name")+"˵����ʩ����������\n");
    	if (ob=present("master yi", this_object()))
    		return notify_fail(ob->query("name")+"����һ�ӣ��㱻���˻�����\n");
    }*/ 
    
    // to shaolin student
    if (dir == "north" && me->query("family/family_name") == "������") 
    	if (me->query("family/generation") > 18 && (!me->query_temp("won_master_yi"))) {
    	  message_vision("һ�ɴ�����$N���˻�����һ�����ϵ�����˵��������һ��������һ�أ��ſ��Դ�ľ���\n",me);
        return notify_fail("");
    } 

    
    return 1;
}
