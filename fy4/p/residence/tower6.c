

inherit __DIR__"ann_residence.c";

void create ()
{
  set("floor",6);

  set ("short", "������"+CHINESE_D->chinese_number(query("floor"))+"��");
  set ("long", @LONG

������Щ��������ˣ�Խ��ö࣬����Խ�࣬
���Ǿ��������ˣ�
���ǲ������������˵����������ͨ��
��������������ҵĴ��£����ǲ��������ͳ����ģ�������ϸ������㲻�����ˡ�


LONG);
        set("exits", ([
  "down" : __DIR__"tower"+(query("floor")-1),
  "up" : __DIR__"tower"+(query("floor")+1), 
]));
  	set("coor/x",-10);
	set("coor/y",-40);
	set("coor/z",query("floor")*40);
	setup();
}

/*
 
               (\~~~/)            
               ( ����)        

               (_____)~��      
   
��������������- FengYun - ������
������������annie 10.2003
������dancing_faery@hotmail.com
*/
