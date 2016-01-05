// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
string stone();


string poem1 = "�ƺƳ�ãã�ٶ̸�������ȱ�����ѳ����б�Ѫ������ʱ��Ѫ����ʱ��һ������޶Ͼ���Ү��Ү��Ϊ����";
string final;


void create()
{
        set("short", "ɽ���ص�");
        set("long", @LONG
�ص�������ͻȻ������γ���һ���޴��ʯ�ң����ڳ����˸���ǧ��ٹ�
������ʯ���ڹ��ߵ���ҫ����˸�����˵�ɫ�ʣ����û�й�������Ѵ������Ƴ�ȥ��
ʯ��һ����һ���޴�İ�ʯ����һ����Ȼ��������
LONG
        );
        set("exits", ([ 
  			"west" : __DIR__"lmidao1",
  			"north" : __DIR__"lmidao3",
  			"northeast" : __DIR__"lmidao4",
		]));
		set("item_desc", ([
			"stone" : (: stone :),
			"��ʯ" : (: stone :),
		]) );
		set("marks/finished", 0);
		set("coor/x",100);
		set("coor/y",30);
		set("coor/z",0);
	    setup();
}

void init(){
   add_action("do_write", "write");
}

string stone(){
	object me;
	me = this_player();
	if(query("marks/finished")){
		tell_object(me, "һ�����ʮ��ƽ���İ�ʯ��\n");
	} else {
		tell_object(me, "һ�����ʮ��ƽ���İ�ʯ������ƽ����һ����ֽ������д��Щ�֣�\n\n"); 
		tell_object(me,query("final"));
		tell_object(me, "�����ƺ����������֣�ֽ�߰����ֳɵı�ī�� \n");
	}
	return "";
}


int do_write(string arg){
   	  object  me, room;
   	  string msg, msg1, msg2;
   	  
	  me = this_player();
	  if(query("marks/finished")){
	      tell_object(me,"�úõ�һ�״ʣ���дЩʲô��\n");
	      return 1;
	  } 
   	  
   	  msg = query("num1")+ query("num2") + query("num3");
   	  msg1 = query("num1")+"��"+ query("num2")+"��"+ query("num3");
   	  msg2 = query("num1")+" "+ query("num2")+" "+query("num3");
   	  
   	   	 
      if(!arg || (arg != msg && arg != msg1 && arg!= msg2)) {
         tell_object(me,"�������д��ȴ�ܾ��ò������С�\n");
         return 1;
      }
      
      tell_object(me, "����һ����������ڿո������˼����֣��ְѱʷ�����ȥ��\n");
      message("vision", me->name()+"��һ�������Ӱ�ʯ�����д�˼����֣��ְѱʷ��˻�ȥ��\n",environment(me), me);

      set("marks/finished",1);
      me->set_temp("marks/guest", 1);
      tell_object(me, "��ֻ���ú������ƺ���ʲô��������һ�¡�\n");
      me->unconcious();
      message("vision", "��ֻ������ǰһ��������һ����Ӱ�ӹ���"+ me->name() +"�Ѿ�ʧȥ����Ӱ��\n", environment(me),me);
      room = find_object(AREA_SHENSHUI"woshi2");
      if(!objectp(room)) room=load_object(AREA_SHENSHUI"woshi2");
      me->move(room);
//	  me->set("marks/enter_ss/��ʯ",1);  	  
   	  return 1;
}



void reorder(){
	
	string final, poem;
	int num1, num2, num3,i;
	
	num1 = random(12)*2 + 2;	
	num2 = random(18)*2 + 24;
	num3 = random(14)*2 + 60;
	
	poem = poem1[0..num1-1]+ "��" + poem1[num1+2..num2-1] + "��" 
			+ poem1[num2+2..num3-1] + "��" + poem1[num3+2..89];
	
	final = "\n		"+ poem[0..5]+"��"+poem[6..11]+"��\n"
			+"		"+ poem[12..17]+"��"+poem[18..23]+"��\n"
			+"		"+ poem[24..31]+"��"+poem[32..39]+"��\n"
			+"		"+ poem[40..49]+"��"+poem[50..59]+"��\n"
			+"		"+ poem[60..73]+"��\n"
			+"		"+ poem[74..81]+"��"+poem[82..89]+"��\n\n";

	
	set("num1", poem1[num1..num1+1]);
	set("num2", poem1[num2..num2+1]);
	set("num3", poem1[num3..num3+1]);
	set("final",final);	
	return;
}

void reset(){
	::reset();
	reorder();
	delete("marks/finished");
}
