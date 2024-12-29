import { Injectable } from '@nestjs/common';

@Injectable()
export class AppService {
  // 비지니스 로직
  getHello(): string {
    return 'Hello World!';
  }
}
